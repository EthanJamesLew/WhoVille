#!/usr/bin/python3

import smtplib
import sys
import argparse
import datetime

    
class SMSBase(object):
    def __init__(self, fileName):
        super(SMSBase, self).__init__()
        
        self.dictionary = readConf(fileName)
        self.number = self.dictionary['RECEIVER']
        
        self.server = smtplib.SMTP("smtp.gmail.com", 587)
        self.server.starttls()
        self.server.login(self.dictionary['GMAIL_USERNAME'], self.dictionary['GMAIL_PASSWD'])
        
    def sendSMS(self, msg):
        self.server.sendmail('', self.dictionary['RECEIVER']+'@'+self.dictionary['SMS_GATE'], msg )
        return

if __name__ == '__main__':
	today = datetime.datetime.now()
    	date = str(today.strftime('''%H.%M'''))
    	mySMS = SMSBase('python/sms.conf')
	parser = argparse.ArgumentParser()
	parser.add_argument('-u', '--users', nargs='+', type=str)
    	parser.add_argument('-s', '--status', type=str)
    	args = parser.parse_args()
    	users = ""
    	for i in args.users:
        	users += i + ", "
    	msg = readTemplate('python/sms.template') % (date, users, args.status )
    	mySMS.sendSMS(msg)

	
    
