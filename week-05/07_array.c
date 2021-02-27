void array() {
    char A[16];
    A[5] = 'a';
    A[6] = A[5];

    int B[4];
    B[0] = 'd';
    B[3] = A[5];
}

int main() {
    array();
    return 0;
}
