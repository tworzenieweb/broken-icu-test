#include "unicode/unum.h"

#include "unicode/ustring.h"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int main(int argc, char **argv) 

{

    UErrorCode status = U_ZERO_ERROR;

    UNumberFormat *fmt = unum_open(UNUM_CURRENCY, NULL, 0, "en_GB", 0, &status);

    int num;

    UChar ures[255];

    char res[255];

    UChar gbp[] = { 'G', 'B', 'P', 0};

    UChar eur[] = { 'E', 'U', 'R', 0};

        

    if (U_FAILURE(status)) {

            printf("FAIL: unum_open\n");

            exit(1);

    }

    

    unum_setAttribute(fmt, UNUM_FRACTION_DIGITS, 4);



    num = unum_getAttribute(fmt, UNUM_FRACTION_DIGITS);

    printf("Digits: %d\n", num);

    

    unum_formatDoubleCurrency(fmt, 123.45, gbp, ures, 254, NULL, &status);

    if (U_FAILURE(status)) {

            printf("FAIL: unum_formatDoubleCurrency\n");

            exit(1);

    }

    

    u_strToUTF8(res, 254, NULL, ures, -1, &status);

    printf("GBP: %s\n", res);



    num = unum_getAttribute(fmt, UNUM_FRACTION_DIGITS);

    printf("Digits: %d\n", num);



    unum_formatDoubleCurrency(fmt, 123.45, eur, ures, 254, NULL, &status);

    if (U_FAILURE(status)) {

            printf("FAIL: unum_formatDoubleCurrency\n");

            exit(1);

    }

    

    u_strToUTF8(res, 254, NULL, ures, -1, &status);

    printf("EUR: %s\n", res);

    

    num = unum_getAttribute(fmt, UNUM_FRACTION_DIGITS);

    printf("Digits: %d\n", num);

}


