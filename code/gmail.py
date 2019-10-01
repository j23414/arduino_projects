#! /usr/bin/env python3
# Tutorial: https://medium.com/home-wireless/how-to-send-mail-with-a-raspberry-pi-via-gmail-fc51f70ac9da

import smtplib

def sendContentAsEmail(content):
    # start talking to the SMTP server for Gmail
    s = smtplib.SMTP('smtp.gmail.com', 587)
    s.starttls()
    s.ehlo()
    # now login as my gmail user
    username='' # Username
    password='' # Password
    s.login(username,password)

    # the email objects
    replyto='' # where a reply to will go
    sendto=[''] # list to send to
    sendtoShow='' # what shows on the email as send to
    subject='Email from Raspberry Pi' # subject line

    # compose the email. probably should use the email python module
    mailtext='From: '+replyto+'\nTo: '+sendtoShow+'\n'
    mailtext=mailtext+'Subject:'+subject+'\n'+content

    # send the email
    s.sendmail(replyto, sendto, mailtext)
    # we’re done
    rslt=s.quit()
    # print the result
    print('Sendmail result=' + str(rslt[1]))

def main():
#    msg="Hello, this is a test of the system.\nHows it going\nMe"
    msg="Hello from Pi, which tastes good"
    with open('output.txt', 'r') as myfile:
      data = myfile.read()
    sendContentAsEmail(data)

if __name__=="__main__":
    main()
