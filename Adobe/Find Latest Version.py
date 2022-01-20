str1 = "10.2.1.3"
str2 = "10.1.1.9"
list1 = str1.split(".")
list2 = str2.split(".")
#print(list1)
#print(list2)
i,j=(0,0)
while i<len(list1) and j<len(list2):
  #print(list1[i],list2[j])
  if list1[i]==list2[j]:
    i+=1
    j+=1
  elif list1[i]>list2[j]:
    print(str1+" is the latest version")
    break
  else:       
    print(str2+" is the latest version")
    break