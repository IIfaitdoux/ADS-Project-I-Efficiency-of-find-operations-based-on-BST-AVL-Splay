#include "tree.h"
#include "testmode.h"
#include <time.h>
#define REPEATITION 100
//store function//
void store(char* TreeType, char* TestMode, int n, double runtime, const char* filename) {
    FILE* f = fopen(filename, "a");
    if (f == NULL) {
        perror("can't open the file");
        return;
    }
    fprintf(f, "%s,%s,%d,%lf\n", TreeType, TestMode, n, runtime);
    fclose(f);
}
//init function//
void init(char* filename) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        perror("can't open the file");
        return;
    }
    fprintf(f, "TreeType,TestMode,N,Runtime(ms)\n");
    fclose(f);
}
int main() {
    // 您可以在这里编写测试代码
    // 3 different types of Tree: BST(0), AVLTree(1), SplayTree(2)//
    char* Tree_Type[3] = {"BST", "AVLTree", "SplayTree"};
    //3 different insert & delete ways//
    char* Test_Mode[3] = {"Increase Insert + Increase Delete", "Increase Insert + Reverse Delete", "Random Insert + Random Delete"};
    //initialize the csv file//
    init("result.csv");
    //start to test//
    for (int n = 1000; n <= 10000; n += 1000) {
        for (int TreeType = 0; TreeType < 3; TreeType += 1) {
            for (int TestMode = 0; TestMode < 3; TestMode += 1) {
                int* insert_array = insert_order(n, TestMode);
                int* delete_array = delete_order(n, TestMode);
                clock_t start, end;
                start = clock();
                //repeat 1000 times//
                for (int i = 0; i < REPEATITION; i += 1) {
                    TreeNode* root = NULL;
                    //insert//
                    for (int j = 0; j < n; j += 1) {
                        root = insert(root, insert_array[j], TreeType);
                    }
                    //delete//
                    for (int j = 0; j < n; j += 1) {
                        root = delete(root, delete_array[j], TreeType);
                    }
                }
                end = clock();
                //counting the runtime(ms)
                double runtime = ((double)(end - start)) / CLOCKS_PER_SEC / REPEATITION * 1000;
                free(insert_array);
                free(delete_array);
                //add the runtime info to the csv file//
                store(Tree_Type[TreeType], Test_Mode[TestMode], n, runtime, "result.csv");
            }
        }
    }
    return 0;
}
