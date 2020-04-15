#include "algo.h"
#include <iostream>
#include <fstream>

using namespace std;
const int MAX_TEST_NAME_SIZE = 32;
int parse_input(const char* input_file, std::vector<int>& input) {
    int N, rc;
    FILE* fp = fopen(input_file, "r");
    if (fp == NULL) {
        goto bad_exit;
    }
    /* Parse input */
    rc = fscanf(fp, "%d", &N);
    if (rc != 1) {
        goto cleanup;
    }
    input.resize(N);
    for (int i = 0; i < N; ++i) {
        rc = fscanf(fp, "%d", &input[i]);
        if (rc != 1) {
            goto cleanup;
        }
    }
    fclose(fp);
    return 0;
    cleanup:
        fclose(fp);
    bad_exit:
        fprintf(stderr, "Invalid input file\n");
        return -1;
    }
int parse_output(const char* reference_file, std::vector<int>& expected) {
    FILE* fp = fopen(reference_file, "r");
    if (fp == NULL) {
        goto bad_exit;
    }
    int rc;
    for (int i = 0, sz = expected.size(), elem; i < sz; ++i) {
        rc = fscanf(fp, "%d", &elem);
        if (rc != 1) {
            goto cleanup;
        }
        expected[i] = elem;
    }
    fclose(fp);
    
    return 0;
    cleanup:
        fclose(fp);
    bad_exit:
        fprintf(stderr, "Invalid reference file\n");
        return -1;
}

int run_test(const char* input_file, const char* reference_file,int argv) {
    int rc; /* return code */
    unsigned nr_it = 0;
    std::vector<int> input, expected;
    /* Parse test data */
    rc = parse_input(input_file, input);
    if (rc) {
        goto bad_exit;
    }
    /* Call algorithm */
    switch (argv)
    {
        case 1:
            {ShellSort(input);
            nr_it = ShellSort(input);
            printf("Numarul de iteratii %d\n",nr_it);
                break;}
        case 2:
            {CountingSort(input);
            nr_it = CountingSort(input);
            printf("Numarul de iteratii %d\n",nr_it);
                break;}
        case 3:
            {CombSort(input);
            nr_it = CountingSort(input);
            printf("Numarul de iteratii %d\n",nr_it);
                break;}
        default:
            printf("Numar algoritm invalid\n");
                return -1;
    }
    expected.resize(input.size());
    /* Parse reference data */
    rc = parse_output(reference_file, expected);
    if (rc) {
        goto bad_exit;
    }
    /* Check answer */
    if (input == expected) {
        printf("Test PASSED!\n");
    } else {
        printf("Test FAILED!\n");
    }
    return 0;
    bad_exit:
        return -1;
    }
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: ./tema <nr_test> <nr_alg>" << endl;
        return -1;
    }
    char input_test[MAX_TEST_NAME_SIZE], 
        reference_file[MAX_TEST_NAME_SIZE];
    
    int i = atoi(argv[1]);
    int nr_alg = atoi(argv[2]);
    sprintf(input_test, "./in/test%d.in", i);
    sprintf(reference_file, "./out/test%d.out", i);
    printf("Running test %d for algoritm %d\n", i, nr_alg);
    if (run_test(input_test, reference_file,nr_alg)) {
        fprintf(stderr, "Failed to run test %d\n", i);
        return -1;
    }
    return 0;
}