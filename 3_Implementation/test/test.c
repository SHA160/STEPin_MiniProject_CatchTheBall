#include "DisplayBorder.h"
#include "unity.h"


/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

int test_read()
{
    // Can ommi the below intialization as it is done at the declaration time
    
     
}
int test_add()
{
    
}

int test_view()
{
   

}
int  test_search()
{

}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_DisplayBorder);
    RUN_TEST(test_setxy);

    /* Close the Unity Test Framework */
    return UNITY_END();
}
