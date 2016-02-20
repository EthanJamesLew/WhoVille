import smtplib
import sys

def readConf(fileName): 
    d = {}
    with open(fileName) as f:
        for line in f:
            if line[0] != '#':                
                try:
                   (key, val) = line.split()
                   d[key] = val
                except:
                    None
    return d

def readTemplate(fileName):
    data = ""
    with open(fileName, 'r') as myfile:
        for line in myfile:
            if line[0] != '#':                
                try:
                   data += line.replace('\n', '')
                except:
                    None
    return data
    
class SMSBase(object):
    def __init__(self, fileName):
        super(SMSBase, self).__init__()
        
        self.dictionary = readConf(fileName)
        self.number = self.dictionary['RECEIVER']
        
        self.server = smtplib.SMTP("smtp.gmail.com", 587)
        self.server.starttls()
        self.server.login(self.dictionary['GMAIL_USERNAME'], self.dictionary['GMAIL_PASSWD'])
        
    def sendSMS(self, receiver, msg):
        self.server.sendmail('', self.dictionary['RECEIVER']+'@'+self.dictionary['SMS_GATE'], msg )
        return

if __name__ == '__main__':
    mySMS = SMSBase('sms.conf')
    mySMS.sendSMS('3107137355', readTemplate('sms.template') % (sys.argv[0],sys.argv[1]))
    #mySMS.sendSMS('3107137355', readTemplate('sms.template') % ('ethan', 'online'))
    
