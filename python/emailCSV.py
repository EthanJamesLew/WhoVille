#!/usr/bin/env python
import imaplib
import smtplib
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication
from email.mime.multipart import MIMEMultipart
from email.MIMEBase import MIMEBase
from email import Encoders
from smtplib import SMTP
import os
import sys

from utils import *

def sendEmail(fileName, receiver, extension='csv'):
    dictionary = readConf('sms.conf')

    if os.path.isfile("who/"+fileName+".who"):
        attachFile = open(fileName)
        htmlFile = open('html/email_success.html')

        ##Build out the success email
        msg = MIMEMultipart()
        msg['Subject'] = fileName + ' --WhoVille Request'

        msg.attach(MIMEText(htmlFile.read(),'html'))

        attachFile = MIMEBase('application', extension)
        attachFile.set_payload(attachFile.read())
        Encoders.encode_base64(attachFile)
        attachFile.add_header('Content-Disposition', 'attachment',  filename=fileName[:-4]+'.csv')
        msg.attach(attachFile)
    else:
        htmlFile = open('html/email_failure.html')

        ##Build out the failure email
        msg = MIMEMultipart()
        msg['Subject'] = 'Request from WhoVille Database Failure'  
        msg.attach(MIMEText(htmlFile.read(), 'html'))

    ##Send message
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.ehlo()
    server.starttls()
    server.login(dictionary['GMAIL_USERNAME'], dictionary['GMAIL_PASSWD'])
    server.sendmail( 'wwhoville@gmail.com', receiver, msg.as_string())
    return
    


def checkSendEmail():
    dictionary = readConf('sms.conf')
    obj = imaplib.IMAP4_SSL('imap.gmail.com','993')
    (retcode, capabilities) = obj.login(dictionary['GMAIL_USERNAME'], dictionary['GMAIL_PASSWD'])
    obj.list()
    obj.select('inbox')

    n=0
    (retcode, messages) = obj.search(None, '(UNSEEN)')
    if retcode == 'OK':

       for num in messages[0].split() :
          n=n+1
          typ, data = obj.fetch(num,'(RFC822)')

    if n > 0:
        print "sending email"
        typ, msg_data = obj.fetch(obj.select()[1][0], '(BODY.PEEK[TEXT])')
        myList = msg_data[0][len(msg_data)-1].split('\n')
        txt = myList[len(myList)-4]
        sendEmail(txt[:-1] + '.who', dictionary['RECEIVER_EMAIL'])
    return

if __name__=='__main__':
    checkSendEmail()
        

