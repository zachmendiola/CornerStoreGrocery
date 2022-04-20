from os import replace
import re
import string
import datetime

def QuantSearch(item):
    dict = {}
    inputFile = open("frequency.dat", "r")
    done = False
    while not done:
        line = inputFile.readline()
        line = line.replace("\n", "")
        if line == '':
            done = True
            if item in dict:
                return dict[item]
            else:
                return -1
            return
        elif line not in dict:
            dict[line] = 1
        else:
            dict[line] += 1


def ItemTotal():
    dict = {}
    inputFile = open("frequency.dat", "r")
    done = False
    today = datetime.datetime.now().date()
    print("----------------------------------------------------------------------------------------------------")
    print("---------------------------------- Items purchased on: "+str(today)+" ----------------------------------")
    print("----------------------------------------------------------------------------------------------------")
    print(" ")
    while not done:
        line = inputFile.readline()
        if line == '':
            for i in dict:
                print("   "+str(dict[i])+" - "+i)
            done = True
            print(" ")
            print(" ")
            break
        elif line not in dict:
            dict[line] = 1
        else:
            dict[line] += 1

def DisplayGraph():
    dict = {}
    inputFile = open("frequency.dat", "r")
    done = False
    while not done:
        line = inputFile.readline()
        if line == '':
            for i in dict:
                bar = {}
                bar['top'] = ""
                bar['mid'] = ""
                bar['bot'] = ""
                GraphBody(bar, dict[i]-1)
                GraphEnd(bar, i, dict[i])
                print(bar['top'])
                print(bar['mid'])
                print(bar['bot'])
                print(" ")
            done = True
            print(" ")
            print(" ")
            break
        elif line not in dict:
            dict[line] = 1
        else:
            dict[line] += 1

def GraphBody(bar, times):
    for i in range(0,times+1):
        bar['top'] += "--"
        bar['mid'] += "  "
        bar['bot'] += "--"
    return bar

def GraphEnd(bar,item, number):
    item = item.replace("\n", "")
    bar['mid'] += "| "+item+" - "+str(number)