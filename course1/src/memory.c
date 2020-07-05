/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 */
#include "../include/common/memory.h"
#include "../include/common/platform.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;

  PRINTF(" Set Value PASSED\n");
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
  PRINTF(" Clear Value PASSED\n");
}

char get_value(char * ptr, unsigned int index){
	
      PRINTF(" Get Value PASSED\n");
      return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }

  PRINTF(" Set all PASSED\n");

}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);

  PRINTF(" Clear all PASSED\n");
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

	int cnt;

	//Declare temp pointer in case of overlap and allocate space	      //for buffer.
	uint8_t *temp;

	PRINTF("In my-memmove, about to allocate memory\n");
	temp = (uint8_t*)malloc(sizeof(uint8_t) * length);
	
	PRINTF("Copying from source to temp array\n");
	//Copy source contents to temporary array
	for(cnt=0; cnt < length; cnt++){
		
		*(temp + cnt) = *(src + cnt);
	}
	
	PRINTF("Copy from temp to destination array\n");
	//Copy from temp array to destination array
	for(cnt=0; cnt < length; cnt++){
		
		*(dst + cnt) = *(temp + cnt);
	}

	free(temp);
	
	PRINTF(" My memmove PASSED\n");

	return dst;
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	
	while(length){
		
		*(dst++) = *(src++);
		length--;
	}

	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	
	while(length){
		
		*(src++) = value;
		length--;
	}

	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
	
	while(length){

                *(src++) = 0;
                length--;
        }
	
	return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	
	size_t incr;
	uint8_t * endsrc, *start_src, temp;

	endsrc = src;
	start_src = src;

	//Get endsrc ptr to end of string
	for(incr=0; incr<length-1; incr++)
		endsrc++;

	// Swap values at end of string with values at the beginning
	for(incr=0; incr<(length-1)/2; incr++){
		
		temp = *endsrc;
		*endsrc = *start_src;
		*start_src = temp;

		start_src++;
		endsrc++;
	}
		
	return src;
}

int32_t * reserve_words(size_t length){
	
	int32_t * reserve;
	reserve = (int32_t *) malloc(length*sizeof(int32_t));

	return reserve;
}

void free_words(int32_t * src){
	
	free(src);
}
