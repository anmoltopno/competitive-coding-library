int search(int *array, int start_idx, int end_idx, int search_val) {

   if( start_idx == end_idx )
      return array[start_idx] <= search_val ? start_idx : -1;

   int mid_idx = start_idx + (end_idx - start_idx) / 2;

   if( search_val < array[mid_idx] )
      return search( array, start_idx, mid_idx, search_val );

   int ret = search( array, mid_idx+1, end_idx, search_val );
   return ret == -1 ? mid_idx : ret;
}

#include <iostream>

int main( int argc, char **argv ) {

   int array[3] = { 10, 20, 30 };

   std::cout << search( array, 0, 2, 9 ) << std::endl;
   std::cout << search( array, 0, 2, 10 ) << std::endl;
   std::cout << search( array, 0, 2, 28 ) << std::endl;
   std::cout << search( array, 0, 2, 55555 ) << std::endl;

   return 0;
}
