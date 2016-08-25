def vowel(word):
        word = word.lower()
        i = 0 
        result = -1
        ch = ''
        while i < len(word) and result == -1:
                ch = word[i]
                if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'u' or ch == 'o':
                        result = i
                i+=1
        return result

def igpay(s):
        lst = s.split(' ')
        vlst = 'aeiuoAEIUO'
        result = list()
        punc =''
        pigs = ''
        for wrd in lst:
                punc =''
                if wrd.find('-') >=0:
                        wrd = wrd.replace("-"," ")
                        wrd = igpay(wrd)
                        wrd = wrd.strip().replace(" ","-")
                else:
                        if wrd[len(wrd)-1] in ',!.?':
                                punc = wrd[len(wrd)-1]
                                wrd = wrd[:len(wrd)-1]
                        if wrd[0] not in vlst:
                                if vowel(wrd) == -1:
                                        wrd = wrd + 'ay'
                                else:
                                        add = wrd[0:vowel(wrd)]
                                        fv = vowel(wrd)
                                        wrd = wrd[fv:]
                                        wrd = wrd + add.lower()
                                        wrd = wrd + 'ay'
                                        if add[0].isupper() == True:
                                                wrd = wrd.title()
                        else:
                                wrd = wrd + 'way'
                wrd += punc
                result.append(wrd)
        
        for i in result:
                pigs += i+' '
        return pigs
cont = 'y'
while cont == 'y':
        init = input("Enter an English phrase: ")
        print(igpay(init))
        cont = input("Continue? (y/n): ").lower()
