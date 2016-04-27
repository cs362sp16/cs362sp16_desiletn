#include <stdio.h>
#include "assert.h"

int myAssertError = 0;

void myAssertTrue(int result, const char *msg){
    if(!result){
        printf("ASSERT FAILED: %s\n", msg);
        myAssertError = 1;
    }
}

void checkAsserts(){
    if(!myAssertError){
        printf("UNIT TEST PASSED.\n");
    }else{
        printf("UNIT TEST FAILED.\n");
    }
}
