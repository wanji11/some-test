#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main() {
    FILE *file1, *file2;
    uint32_t num1, num2;
    uint32_t sum;

    // 첫 번째 파일 열기
    file1 = fopen("file1.bin", "rb");
    if (file1 == NULL) {
        printf("첫 번째 파일을 열 수 없습니다.\n");
        return 1;
    }

    // 두 번째 파일 열기
    file2 = fopen("file2.bin", "rb");
    if (file2 == NULL) {
        printf("두 번째 파일을 열 수 없습니다.\n");
        fclose(file1);
        return 1;
    }

    // 첫 번째 파일에서 숫자 읽기
    fread(&num1, sizeof(uint32_t), 1, file1);
    num1 = ntohl(num1); // 네트워크 바이트 오더에서 호스트 바이트 오더로 변환

    // 두 번째 파일에서 숫자 읽기
    fread(&num2, sizeof(uint32_t), 1, file2);
    num2 = ntohl(num2); // 네트워크 바이트 오더에서 호스트 바이트 오더로 변환

    // 합 계산
    sum = num1 + num2;

    // 결과 출력
    printf("두 숫자의 합: %u\n", sum);

    // 파일 닫기
    fclose(file1);
    fclose(file2);

    return 0;
}





