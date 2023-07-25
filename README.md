# riscv processor

特権命令付きのRISC-Vプロセッサです。
rs32iの命令セットを実装しています。

## サポートしている命令
1. ecall
2. ebreak
3. mret

## cfile
もし、cファイルをコンパイルする場合は、以下のコマンドを実行してください。
```
cd src
vim hoge.c
make
```

必要なツールは以下の通りです。
1. riscv32-unknown-linux-gnu-gcc
2. riscv32-unknown-linux-gnu-objcopy
3. riscv32-unknown-linux-gnu-objdump
4. riscv32-unknown-linux-gnu-ld
5. hexdump
