from flask import redirect, render_template, request, session, url_for
from functools import wraps
import time
import subprocess
import os

class cd:
    """
    Context manager for changing the current working directory
    https://stackoverflow.com/questions/431684/how-do-i-cd-in-python
    """
    def __init__(self, newPath):
        self.newPath = os.path.expanduser(newPath)

    def __enter__(self):
        self.savedPath = os.getcwd()
        os.chdir(self.newPath)

    def __exit__(self, etype, value, traceback):
        os.chdir(self.savedPath)

def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/0.11/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect(url_for("login", next=request.url))
        return f(*args, **kwargs)
    return decorated_function

def compile_code(code,code_filename):
    with cd("./temp"):
        f = open(code_filename+".c","a+")
        f.write(code)
        f.close()
        p = subprocess.Popen([r"/usr/bin/gcc","-Wall","-o",code_filename,code_filename+".c"],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
        stdout,stderr = p.communicate()
        stderr = stderr.decode('utf-8')
        stderr = stderr.split(code_filename+".c:")
        stderr = "".join(stderr)
        return stderr
