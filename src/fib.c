int fib(int n);

int main() {
    fib(3);
    while (1)
        ;
    return 0;
}

// you should input more than 2
int fib(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);

}
