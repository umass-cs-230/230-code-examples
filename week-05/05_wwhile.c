int wwhile() {
    int result = 0;
    int i = 10;
    while(i) {
        result = result + i;
        i--;
    }
    return result;
}

int main() {
    int x = wwhile();
    return 0;
}
