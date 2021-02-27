int absdiff(int x, int y) {
    int result;
    if (x > y) {
        result = x-y;
    }
    else {
        result = y-x;
    }
    return result;
}

int main() {
    int x = 4;
    int y = -5;
    int z = absdiff(x, y);
    return 0;
}
