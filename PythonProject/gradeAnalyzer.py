from os import path
import math
import sys
def openfile():
  fname = input("Enter filename: ")
  count = 0
  while not path.isfile(fname) and count < 2:
    count += 1
    fname = input("File not found. Please re-enter: ")
  if path.isfile(fname):
    opfile = open(fname,'r')
    return opfile
  else:
    return None
#//////////////////////////////////////////////////////////////////////////////////////////////////////////
  
def fieldindex(ifile): #Find the requested fieldname
  fieldname = input("Enter fieldname: ")
  count = 0
  index = -1
  stringname = ''
  fline = ifile.readline().split(',')
  check = False
  while check == False and count < 2:
    for i in range(len(fline)):
      if fieldname.lower().replace(" ","") == fline[i].replace(" ",'').replace("\n",'').lower():
        check = True
        index = i
        stringname = fline[i].strip()
        break
    if check == False:
      count +=1
      fieldname = input(fieldname +" does not match any field. Please re-enter: ").lower()
  try:
    last = ifile.tell()
    r = ifile.readline().split(',')
    if r[index].isalpha() == True:
      raise TypeError
  except TypeError:
      print(fieldname + " is not a numeric field!\nprogram terminated.")
      sys.exit()
  ifile.seek(last)
  return (str(index), stringname)
#//////////////////////////////////////////////////////////////////////////////////////////////////////////

def stdev(vlist):
  mean = sum(vlist)/len(vlist)
  sumstd = 0
  for num in vlist:
    sumstd += (num - mean)**2
  std = (sumstd/len(vlist))**0.5
  return round(std,2)
#//////////////////////////////////////////////////////////////////////////////////////////////////////////

def median(vlist):
  vlist.sort()
  if len(vlist) % 2 == 0:
    result = round((float(vlist[len(vlist)//2] + vlist[len(vlist)//2-1]))/2.0,2)
  else:
    result = round(vlist[len(vlist)//2])
  return round(result,2)
#//////////////////////////////////////////////////////////////////////////////////////////////////////////



#-----------------------------MAIN-------------------------------
f = openfile() #Open the filed
if f != None:
  i = -1
  i, field = fieldindex(f)
  i = int(i)
  
  r = f.readline().split(',')
  data = []
  while len(r) > i:
    data.append(int(r[i]))
    r = f.readline().split(',')
  print("\t" + field + " Summary Data")
  print("________________________________________________________________\n")
  print("\tNumber of scores: "+str(len(data)))
  print("\tMean: "+str(round(sum(data)/len(data),2)))
  print("\tStandard Deviation: " + str(stdev(data)))
  print("\tMedian: " + str(median(data)))
  print("\tMin: " + str(min(data)))
  print("\tMax: " + str(max(data)))
  