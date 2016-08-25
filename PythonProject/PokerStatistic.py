#This program simulates the statistic for 100000 draws of poker game
import random

class Carddeck:
  def __init__(self, lst = None, iNext = 0):
    self.cardlist = list(range(52))
    lstvalue = ['2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A']
    lstsuits = ['C', 'S', 'D', 'H' ]
    i = 0
    for suit in lstsuits:
      for val in lstvalue:
        self.cardlist[i] = val + suit
        i +=1

  def __repr__(self): #Need explanation
    return str(self.cardlist)

  def shuffle(self):
    self.iNext = 0
    random.shuffle(self.cardlist)

  def dealcard(self):
    self.iNext += 1
    if self.iNext >52:
      self.shuffle()
      self.iNext = 1
    return self.cardlist[self.iNext-1]

  def dealhand(self):
    lst = list()
    for i in range(5):
      lst.append(self.dealcard())
    return Pokerhand(lst)

class Pokerhand:
  def __init__(self,lst):
    self.hand = lst
    self.rank()

  def __repr__(self):
    return str(self.hand)
  
  def rank(self):
    valrank = [self.hand[0][0],self.hand[1][0],self.hand[2][0],self.hand[3][0],self.hand[4][0]]
    suirank = [self.hand[0][1],self.hand[1][1],self.hand[2][1],self.hand[3][1],self.hand[4][1]]
    for i in range(5):
      if valrank[i] == 'T':
        valrank[i] = '10'
      elif valrank[i] == 'J':
        valrank[i] = '11'
      elif valrank[i] == 'Q':
        valrank[i] = '12'
      elif valrank[i] == 'K':
        valrank[i] = '13'
      elif valrank[i] == 'A':
        valrank[i] = '1'

    #Define Dictionary
    valDict = {}
    suitDict = {}
    #Count number value
    for v in valrank:
      if v in valDict:
        valDict[v] += 1
      else:
        valDict[v] = 1
    valrank.sort()
    #Count number of suit
    for s in suirank:
      if s in suitDict:
        suitDict[s] += 1
      else:
        suitDict[s] = 1
    
    
    maxValue = max(valDict, key = valDict.get)
    minValue = min(valDict, key = valDict.get)
    maxSuit = max(suitDict, key = suitDict.get)
    minSuit = min(suitDict, key = suitDict.get)

    if suitDict[maxSuit] == 5:
      if '1' in valrank: #Case: Ace is in the hand
        result = True
        for i  in range(4):
          if int(valrank[i+1]) - int(valrank[i]) != 1:
            result = False
            
        if result == False:
          result = True
          valrank[0] = '14'
          valrank.sort()
          for i in range(4):
            if int(valrank[i+1]) - int(valrank[i]) != 1:
              result = False
        if result == True:
          return 8
        else:
          return 5
      else:
        for i in range(4):
          if int(valrank[i+1]) - int(valrank[i]) != 1:
            return 5 #Flush       
        return 8 #Straight Flush

    elif valDict[maxValue] == 4 and suitDict[maxSuit] == 2:
      return 7 #Four of a King
    elif valDict[maxValue] == 3:
      if valDict[minValue] == 2:
        return 6 #Full House
      else:
        return 3 #Three of the King
    elif valDict[maxValue] == 2:
      if len(valDict) == 3:
        return 2 #Two pair
      elif len(valDict) == 4:
        return 1 #One Pair
    else:
      for i in range(4):
        if int(valrank[i+1]) - int(valrank[i]) != 1:
          return 0 #High Card
      return 4 #Straight
      

test = Carddeck()
test.shuffle()
result = {0:0,1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0}
for i in range(100000): #Draw 100000 time
  hand = test.dealhand()
  result[hand.rank()] +=1

display = {"Straight Flush":result[8],"Four of a Kind":result[7],"Full house":result[6],
      "Flush":result[5],"Straight":result[4],"Three of a Kind":result[3],"Two pair":result[2],
      "One pair":result[1],"High card":result[0]}
pr = " "
s = 0
for w in sorted(display, key=display.get, reverse=False):
  pr = w
  s += display[w]
  for i in range(20 - len(w)):
    pr += " "
  print(pr + ": " + str(display[w]))
print("Total card draw: " + str(s))

