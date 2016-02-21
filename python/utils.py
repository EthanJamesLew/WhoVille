def readConf(fileName): 
    d = {}
    with open("conf/" + fileName) as f:
        for line in f:
            if line[0] != '#':                
                try:
                   (key, val) = line.split()
                   d[key] = val
                except:
                    None
    return d

def readTemplate(fileName):
    data = ""
    with open("conf/" +fileName, 'r') as myfile:
        for line in myfile:
            if line[0] != '#':                
                try:
                   data += line.replace('\n', '')
                except:
                    None
    return data
