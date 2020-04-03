import pyrebase # https://github.com/thisbejim/Pyrebase
import datetime
import time
import sys
from secret import *  # Contains keys and account information

SAMPLE_TIME = 5

config = {
  "apiKey" : FIREBASE_KEY,
  "authDomain" : "backyardweather-ae128.firebaseapp.com",
  "databaseURL" : "https://backyardweather-ae128.firebaseio.com",
  "storageBucket" : "backyardweather-ae128.appspot.com"
}

while True:
    try:
        print("Connecting to Firebase")
        firebase = pyrebase.initialize_app(config)
        auth = firebase.auth()
        user = auth.sign_in_with_email_and_password(FIREBASE_EMAIL, FIREBASE_PASSWORD)
        print("Logged in as: {}".format(user["email"]))
        db = firebase.database()
        timestamp = int(datetime.datetime.now().timestamp()*1000)
        temp = float(input("Enter temp: "))
        data = {"date" : timestamp, "temp" : temp}
        print("Writing: {}".format(data))
        db.child(user["localId"]).child("observations").push(data, user["idToken"])
        print("Success")
    except: 
        print("Error Occurred!")
        print(sys.exc_info())
    print()
    print("Waiting {} seconds".format(SAMPLE_TIME))
    time.sleep(SAMPLE_TIME)

