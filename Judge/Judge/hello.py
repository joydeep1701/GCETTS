#from sql import *
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import gettempdir
import time
import api
from werkzeug.datastructures import ImmutableMultiDict
#from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response
# custom filter
#app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = gettempdir()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def hello():
    return render_template('editor.html')

@app.route("/api/compile", methods=["GET", "POST"])
def apicompile():
    if request.method == "POST":
        data = dict(request.form)
        code = str(data['code'][0])
        #code = request.form.post('code')
        code_filename = str(time.time())
        stderr = api.compile_code(code,code_filename)
        if stderr == '':
            return code_filename+"|~|"+"0"+"|~|"+"Compilation Successful"
        else:
            return code_filename+"|~|"+"1"+"|~|"+stderr
    else:
        return "Invalid Request"
@app.route("/api/run",methods=["GET","POST"])
def  apirun():
    #return "Scheduled to run"
    if request.method == "POST":
        id = request.form.get('pid');
        stdout = api.run_code(id)
        return stdout
    else:
        return "Aw, Something is wrong"
