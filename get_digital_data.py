import pandas as pd


def count_pulses(data):
    rising = 0
    falling = 0
    last_sample = data[0]
    for sample in data:
        if (last_sample==0)and(sample==1):
            rising+=1
        if (last_sample==1)and(sample==0):
            falling+=1
        last_sample = sample
    return [rising, falling]
    
    
def getDataPacket(clk,data):
    last_sample = clk[0]
    data_out = []
    for i in range(0,len(clk)):
        if (last_sample==0)and(clk[i]==1):
            #rising
            data_out.append(data[i])
        last_sample = clk[i]
    return data_out
    
def splitPacketToBytes(packet):
    bytecounter = 0
    current_byte = 0
    bytes_pack = []
    for byte in packet:
        if byte==1:
            current_byte = current_byte | (1<<bytecounter)
        bytecounter+=1
        if (bytecounter==16):
            bytes_pack.append(current_byte)
            current_byte = 0
            bytecounter = 0
    bytes_pack.append(current_byte)
    return bytes_pack
    
df = pd.read_csv('digifiz3.csv')

clock_main = df[' Channel 5'].to_list()
clock_strobe = df[' Channel 6'].to_list()
data = df[' Channel 7'].to_list()

dp = getDataPacket(clock_strobe,data)

print(dp)
print(len(dp))

print(splitPacketToBytes(dp))   

