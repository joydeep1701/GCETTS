from matplotlib import pyplot as plt
import numpy as np

def plotthecurve(xdata,ydata,xlbl,ylbl,xmin=0,ymin=0):    
    f, ax = plt.subplots(1)
    f.set_size_inches(10,10) 
    plt.xlabel(xlbl)
    plt.ylabel(ylbl)
    ax.plot(xdata, ydata,'bo-')
    ax.set_ylim(ymin=ymin)
    ax.set_xlim(xmin=xmin) 
    
    major_ticks = np.arange(0, 101, 20)                                              
    minor_ticks = np.arange(0, 101, 5)                                               

    ax.set_xticks(np.arange(xmin,max(xdata)*1.1,max(xdata)/10)) 
    ax.set_xticks(np.arange(xmin,max(xdata)*1.1,max(xdata)/50),minor=True)   
    #ax.set_xticks(minor_ticks, minor=True)
    ax.set_yticks(np.arange(ymin,max(ydata)*1.1,max(ydata)/10))
    ax.set_yticks(np.arange(ymin,max(ydata)*1.1,max(ydata)/50),minor=True)
    #ax.set_yticks(major_ticks)                                                       
    #ax.set_yticks(minor_ticks, minor=True)  
    ax.grid(which='both')                                                            

    # Grid Bar Opacity:                               
    ax.grid(which='minor', alpha=0.3)                                                
    ax.grid(which='major', alpha=0.8) 

    plt.show(f)