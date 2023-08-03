# riscv processor

特権命令付きのRISC-Vプロセッサです。
rs32i + zicar + machine modeの特権命令セットを実装しています。
インオーダプロセッサなのでfence命令は実装していません。

## 実行
filename.vを追加し、その中で.hexファイルまでのパスをdefineしてください.
```bash
# example
`define FILENAME "/path/to/hoge.hex"
```

## サポートしている命令
1. ecall
2. ebreak
3. mret
4. wfi
5. csrrw
6. csrrs
7. csrrc
8. csrrwi
9. csrrsi
10. csrrci

## make your code from c files
もし、cファイルをコンパイルする場合は、以下のコマンドを実行してください。
```bash
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
6. python3

ここからダウンロードできます。
https://github.com/riscv-collab/riscv-gnu-toolchain

詳しくはsrc/Makefileを参照してください。

## future work
1. パイプライン化
2. supervisor modeの実装
