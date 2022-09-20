//
// Created by HongGyu Song on 2022/09/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
    char szData[64];
    struct NODE* next;
} NODE;

NODE* g_pHead = NULL;

/**
 * 연결 리스트 전체 데이터 출력
 */
void PrintList(void) {
    NODE* pHead = g_pHead;
    while (pHead != NULL) {
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }

    putchar('\n');
}

int InsertNewNode(char* pszData) {
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE)); // pNode 가리키는 메모리를 0으로.
    strncpy(pNode->szData, pszData, sizeof(pNode->szData));

    if (g_pHead == NULL) {
        g_pHead = pNode;
    }
    else {
        pNode->next = g_pHead;
        g_pHead = pNode;
    }

    return 1;
}

int main() {
    // List 테스트를 위한 코드.
    InsertNewNode("TEST01");
    PrintList();

    InsertNewNode("TEST02");
    PrintList();

    InsertNewNode("TEST03");
    PrintList();
    return 0;
}