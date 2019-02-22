#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


struct IntArray{
 int length;
 int *dataPtr;
};

struct IntArray *mallocIntArray(int length){
	struct IntArray *returnValue = NULL;		//creates NULL struct IntArray
	returnValue = (struct IntArray *)malloc(sizeof(struct IntArray)); //sets size of struct IntArray
	returnValue->length = length;		//sets length to given length
	returnValue->dataPtr = (int *) malloc(sizeof(int) * length);		//takes size of int and reseverse sizeof(int) * length space
	for(int i=0; i<length; i++ ){		//loop through array
		returnValue->dataPtr[i]=0;		//set all data in array to 0
	}
	return returnValue;
};

void freeIntArray(struct IntArray **arrayPtr){
	if((arrayPtr != NULL) && ((*arrayPtr) !=NULL) )	// don't dereference a bad pointer.
	{
		for(int i=0; i< (*arrayPtr)->length; i++)			// un-init all memory to 0's.
		{
			(*arrayPtr)->dataPtr[i] = 0;
		}

		free((*arrayPtr)->dataPtr);			// de-allocate the array of integers.
		(*arrayPtr)->dataPtr =NULL;			// set the pointer to null.
		(*arrayPtr)->length =0;			// set the size to 0.
		free((*arrayPtr));				// free the struct pointer.
		(*arrayPtr) = NULL;				// set value of the passed in pointer to null.
	}
	else
	{
		fprintf(stderr,"Error bad pointer found.\n");
	}
}

void readIntArray(struct IntArray *array){
	int num;
	bool start =true;
	char *end=NULL; //points to end of input
	char buf[32]; //buffer size 32 for ints
	for (int i =0; i < array->length; i++ ){	//asks for ints to fill array
		while (fgets(buf, sizeof(buf), stdin)){	//until input
			 			num = strtol(buf, &end, 10);		//num == input
						if(start == true){		//if first input ask for input
							start=false;
							printf("Enter number: ");
						} else if (end == buf || *end != '\n') {		//if error ask again
								printf("ERROR, Please Enter Integer: ");
		        } else{	//correct input
							break;
						}

		    }
				array ->dataPtr[i]=num;   //sets data to given int
				printf("Enter number: ");
	}
}

void swap(int *xp, int *yp){
	int t0 = *xp;			//set ints to pointers
	int t1 = *yp;
	*xp = t1;					//set pointers to ints
	*yp = t0;					// swap finished
 }

void sortIntArray(struct IntArray *array){
	for(int i=0; i < array->length; i++){
		bool check = false;		//loop through array i = 0
		for(int j = i+1; j< array->length; j++){	//loop through array j = i+1
			check = *(array->dataPtr+i) > *(array->dataPtr+j);		// compare two ints, true if first is bigger
			if(check == true){
				swap(&(array->dataPtr[i]), &(array->dataPtr[j]));				// swap if bigger is first
			}
		}
	}
}

void printIntArray(struct IntArray *array){
	printf("[");
	int i;
	for(i=0; i<	array->length - 1; i++){	//loop through array
		printf("%d, ",array->dataPtr[i]);		//print each instance fo data
	}
	printf("%d]\n",array->dataPtr[i]);
}

int main(){
	printf("Enter length of the array: ");
  int length;
  scanf("%d", &length);

	struct IntArray *array = mallocIntArray(length);
	readIntArray(array);
	sortIntArray(array);
	printIntArray(array);
	freeIntArray(&array);
}
