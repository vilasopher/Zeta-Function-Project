# zetarunner.py
# Author: Vilas Winstein

import sys
import os
from itertools import takewhile

s2b = lambda x : True if x[0] == 'T' else False

programOutput = os.popen('./zeta_test ' + sys.argv[1] + ' ' + sys.argv[2] + ' ' + sys.argv[3]).read()[:-1]

print(programOutput)

programAnswer = ''.join(list(reversed(list(takewhile(lambda x : x != '\n', reversed(programOutput))))))

closeEnough = s2b(os.popen('./checkanswer.wls \"' + sys.argv[1] + ' + ' + sys.argv[2] + ' I\" \"' + programAnswer + '\" \"' + sys.argv[3] + '\"').read())

print(closeEnough)
