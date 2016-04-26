#include <stdio.h>
#include "assert.h"

void assertEquals(int result, char *action){
    if(!result){
        printf("ASSERT FAILED: %s\n", action);
        error = 1;
    }
}

void checkAsserts(){
    if(!error){
        printf("UNIT TEST PASSED.\n");
    }else{
        printf("UNIT TEST FAILED.\n");
    }
}
