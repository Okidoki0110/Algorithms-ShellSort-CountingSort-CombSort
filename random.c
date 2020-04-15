#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    srand(time(NULL));
    FILE *input_file = fopen(argv[1], "w");
    fprintf(input_file, "%d\n", atoi(argv[2]));
    // generare numere random de la -50000 la 50000 (pentru ca counting sort sa nu crape)
    for (int i = 0; i < atoi(argv[2]); i++) {
       fprintf(input_file, "%d ", rand() % 100000 - 50000);
    }

    // generare numere crescatoare
    // am folosit pentru testul /out/test8
    //for (int i = 1; i <= atoi(argv[2]); i++) {
    //   fprintf(input_file, "%d ", atoi(argv[2]) - i);
    // }

    // generare numere descrescatoare
    // am folosit pentru testul /out/test9
    // for (int i = 0; i < atoi(argv[2]); i++) {
    //     fprintf(input_file, "%d ", atoi(argv[2]));
    // }

    //pentru directorul other_test 

    // genereaza numere crescatoare pana la o anumita valoare
    //apoi se continua cu o valoare constanta
    // int consta = atoi(argv[2]) - 100;
    // int i;
    // for (i = 0; i < atoi(argv[2]); i++) {
    //     if(i > consta)
    //         fprintf(input_file, "%d ", i );
    //     else
    //         fprintf(input_file, "%d ", consta );
    // }

    // genereaza numere descrescatoare pana la o anumita valoare
    // apoi se continua cu o valoare constanta
    // int consta = atoi(argv[2]) - 100;
    // int i;
    // for ( i = atoi(argv[2]); i > 0; i--) {
    //     if(i > consta)
    //         fprintf(input_file, "%d ", i );
    //     else
    //         fprintf(input_file, "%d ", consta );
    // }

    // int consta = atoi(argv[2]) - 100;
    // int i;
    // for ( i = atoi(argv[2]); i > 0; i--) {
    //     if(i < consta)
    //         fprintf(input_file, "%d ", i );
    //     else
    //         fprintf(input_file, "%d ", consta );
    // }

    fclose(input_file);
    return 0;
}