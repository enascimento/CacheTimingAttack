/*
 * cache_evict.c
 * Joseph C. Bonneau
 * April 2006
 *
 * Cache eviction routines
 */

#include "cache_evict.h"
#include "time.h"
#include "xio.h"
#include "stdio.h"
//#include "profile.h"

#include "xtmrctr.h" // for timer API
#include "xparameters.h" // for component addresses
#include "xil_cache.h" // cache API

//char * cleaner_start;
//char * mem_start;
//
//char * main_start;
//char * hs_start;
//char * dhs_start;

// Prototypes


// The private counter used for timestamping events
XTmrCtr timer;

void cache_evict_init()
{
	int status = 0;

	status = XTmrCtr_Initialize(&timer, XPAR_XPS_TIMER_0_DEVICE_ID);

	if (status != XST_SUCCESS)
	{
		xil_printf("Timer initialization failure!\r\n");
	}
	else
	{
		XTmrCtr_SetResetValue(&timer, 0, 0x00000000);
	}

	XTmrCtr_Reset(&timer, 0);
	XTmrCtr_Start(&timer, 0);

	cache_clean(0);

	//
	//  printf("\nT_0: %p (%d)", (char *) getT0Start(), ((int) getT0Start()) / 4096);
	//  printf("\nT_1: %p (%d)", (char *) getT1Start(), ((int) getT1Start()) / 4096);
	//  printf("\nT_2: %p (%d)", (char *) getT2Start(), ((int) getT2Start()) / 4096);
	//  printf("\nT_3: %p (%d)", (char *) getT3Start(), ((int) getT3Start()) / 4096);
	//
	//#ifdef L1_EVICT
	// printf("\nEvicting L1 cache");
	// mem_start = malloc(L1_CACHE_SIZE);
	//#elif defined(PENT_4)
	// printf("\nEvicting L2 Cache, Pentium IV/Xeon");
	//#elif defined(PENT_3)
	//  mem_start = malloc(L2_CACHE_SIZE * 2);
	// printf("\nEvicting L2 Cache, Pentium III");
	//
	// char * tableStart = (char *) getT3Start();
	//  int tableStartOffset = ((int) tableStart) % L2_CACHE_OFFSET;
	//
	//
	//   cleaner_start = ((char *) mem_start) - (((int) mem_start) %
	//		 L2_CACHE_OFFSET) + tableStartOffset ;
	//
	//  while(cleaner_start < mem_start)
	//    cleaner_start += L2_CACHE_SIZE;
	//
	//  main_start = cleaner_start;
	//  hs_start = main_start + ((int) getHSTableStart()) - ((int) getT3Start());
	//  dhs_start = main_start + ((int) getDHSTableStart()) - ((int) getT3Start());
	//
	//#elif defined(SPARC)
	//  mem_start = malloc(L2_CACHE_SIZE * 2);
	// printf("\nEvicting L2 Cache, SPARC");
	//
	// char * tableStart = (char *) getT3Start();
	//  int tableStartOffset = ((int) tableStart) % L2_CACHE_OFFSET;
	//
	//
	//   cleaner_start = ((char *) mem_start) - (((int) mem_start) %
	//		 L2_CACHE_OFFSET) + tableStartOffset ;
	//
	//  while(cleaner_start < mem_start)
	//    cleaner_start += L2_CACHE_SIZE;
	//
	//  main_start = cleaner_start;
	//  hs_start = main_start + ((int) getHSTableStart()) - ((int) getT3Start());
	//  dhs_start = main_start + ((int) getDHSTableStart()) - ((int) getT3Start());
	//
	//#endif
}

void cache_clean(char * start)
{
	// Flush the cache...
	Xil_DCacheFlush();
	//Xil_ICacheFlush();

	//  int i, j;
	//#ifdef PENT_3
	//  char * index = start;
	//
	//  for(j = 0; j < L2_CACHE_ASSOC; j++){
	//    for(i = 0; i < TABLE_SIZE; i += L2_CACHE_LINE_SIZE)
	//      ++index[i];
	//    index += L2_CACHE_OFFSET;
	//  }
	//
	//#elif defined(SPARC)
	//  char * index = start;
	//
	//  for(j = 0; j < L2_CACHE_ASSOC; j++){
	//    for(i = 0; i < TABLE_SIZE; i += L2_CACHE_LINE_SIZE)
	//      ++index[i];
	//    index += L2_CACHE_OFFSET;
	//  }
	//
	//#elif defined(PENT_4)
	//    for(i = 0; i < TABLE_SIZE; i += L2_CACHE_LINE_SIZE){
	//      asm("clflush (%0)" :: "r" (start + i));
	//    }
	//#endif
}
//
//void l1_cache_evict()
//{
//  int i;
//  for(i = 0; i < L1_CACHE_SIZE; i += L1_LINE_SIZE)
//    mem_start[i]++;
//
//}
//
//void w_cache_evict()
//{
//
//#ifdef L1_EVICT
//  l1_cache_evict();
//#elif defined(PENT_3)
//  l1_cache_evict();
//  cache_clean(main_start);
//  cache_clean(main_start + 1024);
//  cache_clean(main_start + 2048);
//  cache_clean(main_start + 3072);
//#elif defined(SPARC)
//  l1_cache_evict();
//  cache_clean(main_start);
//  cache_clean(main_start + 1024);
//  cache_clean(main_start + 2048);
//  cache_clean(main_start + 3072);
//#else
//  cache_clean((char *) getT0Start());
//  cache_clean((char *) getT1Start());
//  cache_clean((char *) getT2Start());
//  cache_clean((char *) getT3Start());
//#endif
//}
//
//
//void hs_cache_evict(){
//#ifdef L1_EVICT
//  l1_cache_evict();
//#elif defined(PENT_3)
//  cache_clean(hs_start);
//#elif defined(SPARC)
//  cache_clean(hs_start);
//#else
//  cache_clean(getHSTableStart());
//#endif
//
//}
//void dhs_cache_evict(){
//#ifdef L1_EVICT
//  l1_cache_evict();
//#elif defined(PENT_3)
//  cache_clean(dhs_start);
//#elif defined(SPARC)
//  cache_clean(dhs_start);
//#else
//  cache_clean(getDHSTableStart());
//#endif
//}

/*
 * Get accurate cycle count from processor.
 */
double timestamp(void)
{
	return ((double)XTmrCtr_GetValue(&timer, 0) / 125000000); // the clock frequency, which gives real-time
}
