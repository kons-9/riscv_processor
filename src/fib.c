int fib(int n);

int main() {
    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    int c = fib(5);  // 5
    int d = 1;
    int e = c + d;
    while (1)
        ;
    return 0;
}

// you should input more than 2
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
