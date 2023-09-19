#include<stdio.h>


int main() {
    // Write binary data to a file
    FILE *writeFile = fopen("binary_data.bin", "wb");
    if (writeFile == NULL) {
        printf("Cannot open file for writing.\n");
        return 1;
    }

    int data[] = {10, 20, 30, 40, 50};
    size_t dataSize = sizeof(data);
    size_t elementsCount = sizeof(data) / sizeof(int);

    fwrite(data, sizeof(int), elementsCount, writeFile);
    fclose(writeFile);

    // Read binary data from the file
    FILE *readFile = fopen("binary_data.bin", "rb");
    if (readFile == NULL) {
        printf("Cannot open file for reading.\n");
        return 1;
    }

    int readData[5];
    fread(readData, sizeof(int), elementsCount, readFile);
    fclose(readFile);

    printf("Data read from the file:\n");
    for (size_t i = 0; i < elementsCount; i++) {
        printf("%d ", readData[i]);
    }

    return 0;
}
