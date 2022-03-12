#include "big_O.h"


void checkTime(void(*sort_functions_t) (int *, size_t),
               void(*generating_functions_t) (int *, size_t),
               size_t size, char *experimentName) {

    static size_t runCounter = 1;

    static int innerBuffer[10000000];
    generating_functions_t(innerBuffer, size);

    printf("Run #%zu | ", runCounter++);
    printf("Name: %s\n", experimentName);

    double time;
    TIME_TEST({sort_functions_t(innerBuffer, size);}, time);

    printf("Status: ");

    if (is_ordered(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

        char fileName[256];
        sprintf(fileName, "./data/%s,csv", experimentName);
        FILE *f = fopen(fileName, "a");

        if(f == NULL) {
            printf("FileOpenError %s", fileName);
            exit(604);
        }

        fprintf(f, "%zu; %.3f s.\n", size, time);
        fclose(f);
    } else {
        printf("Is non sorted, Wrong!\n");

        outputArray_(innerBuffer, size);

        exit(604);
    }
}

void timeMeasure() {
    sort_functions_t sorts[] = {
    };

    const unsigned nFunctions = ARRAY_SIZE(sorts);

    generating_functions_t genFunctions[] = {
            {generate_random_sequence, "randomArray"},
            {generate_ordered_sequence, "orderedArray"},
            {generate_ordered_backward, "orderedBackwards"}
    };

    const unsigned CASES_N = ARRAY_SIZE(genFunctions);

    for (size_t size = 10000000; size <= 1000000000; size += 10000) {
        printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
        printf("Size: %lld\n", size);
        for (int i = 0; i < nFunctions; ++i) {
            for (int j = 0; j < CASES_N; ++j) {
                static char fileName[128];

                sprintf(fileName, "%s_%s_time",
                        sorts[i].name, genFunctions[j].name);

                checkTime(sorts[i].sort,
                          genFunctions[j].generate,
                          size, fileName);
            }
        }
        printf("\n");
    }
}