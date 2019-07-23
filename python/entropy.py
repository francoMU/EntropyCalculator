



def readdump(fileName):

    read_flag = False

    with open(fileName) as f:
        for line in f:
            lst = line.trim().split()
            if lst[0] == "ITEM:":
                if lst[1] == "ATOMS":
                    read_flag = True
                else:
                    read_flag = False
            if read_flag:

