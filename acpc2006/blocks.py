with open("blocks.in") as f:
    comp = 1
    while True: 
        line = f.readline().rstrip()
        if line == "0":
            exit(0)
        blocks_number = list(map(int,line))
        valid = True
        number_of_blocks = len(blocks_number)
        
        if number_of_blocks==1:
            valid = False
        else:
            following = {
                1: [4,5],
                2: [],
                3: [4,5],
                4: [2,3],
                5: [8],
                6: [2,3],
                7: [8],
                8: [6,7]
            }
            # print(blocks_number)
            for idx,block_num in enumerate(blocks_number):
                if idx==0:
                    # print("Block num", block_num)
                    if block_num!=1:
                        # print(block_num)
                        valid = False
                        # print("S1")
                        break
                    else:
                        if blocks_number[1] not in following[1]:
                            valid = False
                            # print("S2")
                            break
                elif idx==-1+number_of_blocks:
                    if block_num!=2:
                        valid = False
                        # print("S3")
                        break
                else:
                    if blocks_number[idx+1] not in following[blocks_number[idx]]:
                        valid = False
                        # print("idx", idx)
                        # print("BL", blocks_number[idx+1])
                        # print("F", following[blocks_number[idx]])
                        # print("S4")
                        break
        line_report = f"{comp}. VALID"
        if valid is False:
            line_report = f"{comp}. NOT"
        print(line_report)
        comp+=1
