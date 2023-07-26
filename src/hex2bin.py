# hex to bin file
import os
import sys


# get files of current directory
def get_files(path):
    files = []
    for file in os.listdir(path):
        if os.path.isfile(os.path.join(path, file)):
            files.append(file)
    return files

# hex to bin
def hex2bin(hex_file, bin_file):
    with open(hex_file, 'r') as f:
        with open(bin_file, 'w') as b:
            cnt = 0
            for line in f.readlines():
                n = int(line, 16)
                bina = "{:032b}".format(n)
                readable = "{:08x}".format(cnt) + ": " + bina[0:7] + "_" + bina[7:12] + "_" + bina[12:17] + "_" + bina[17:20] + "_" + bina[20:25] + "_" + bina[25:32] + "\n"
                b.write(readable)
                cnt += 4
    return bin_file

if __name__ == '__main__':
    # first argument is the path of the hex file
    # second argument is the path of the binary file
    argv = sys.argv
    if len(argv) == 1:
        # use get_files to get all the files in the current directory
        files = get_files(os.getcwd())
        for file in files:
            if file.endswith(".hex"):
                hex_file = file
                bin_file = file.replace(".hex", ".binary")
                hex2bin(hex_file, bin_file)
    elif len(argv) == 2:
        hex_file = argv[1]
        bin_file = hex_file.replace(".hex", ".binary")
        hex2bin(hex_file, bin_file)
    elif len(argv) == 3:
        hex_file = argv[1]
        bin_file = argv[2]
        hex2bin(hex_file, bin_file)
    else:
        print("Usage: python hex2bin.py hex_file bin_file")
        exit(1)
