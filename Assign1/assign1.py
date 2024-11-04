import traceback

expression:str=input('Enter Input Expression: ')
operators:list[str]=['+','-','*','/','(',')',' ']
digits:list[str]=['0','1','2','3','4','5','6','7','8','9']
token_cls:str=''
token_lst:list[str]=[]
attribute:str=''
exception:bool=False
space=False

try:
    for char in expression:
        if char in operators:
            if attribute!= '':
                token_lst.append(f'( {token_cls}, {attribute} )')
            if char=='(' or char==')':
                token_lst.append(f'( , {char} )')
            elif char!=' ':
                token_lst.append(f'( {'opr'}, {char} )')
            attribute=''
            token_cls=''
            
        else:
            if attribute=='':
                if char in digits:
                    token_cls='const'
                else:
                    if (ord(char)>=65 and ord(char)<=90) or (ord(char)>=97 and ord(char)<=122):
                        token_cls='id'
                    else:
                        exception=True
                        raise Exception('invalid character. use only alphabet')
            else:
                if (token_cls=='const') and (char not in digits):
                    exception=True
                    raise Exception('invalid variable or number')
            attribute+=char 
            
except Exception as e:
    tb_str = traceback.format_exc()
    print("An error occurred:\n", tb_str)
    for pairs in token_lst:   
        print(pairs) 
    
if not exception :
    if attribute!='':
        token_lst.append(f'( {token_cls}, {attribute} )')
    print('Tokens Generated:')
    for pairs in token_lst:   
        print(pairs)
            