int dowhile() {
    int result = 0;
    int i = 10;
    do {
        result = result + i;
        i--;
    } while(i);
    return result;
}

int main() {
    int x = dowhile();
    return 0;
}
