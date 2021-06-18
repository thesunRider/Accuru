import pdb
import sys
import time

class PdbDetach(pdb.Pdb):
	use_rawinput = False
	time = 0
	offset_auto_adjust = False
	error_avrg = 0


	def __init__(self, *args, **kwargs):
		pdb.Pdb.__init__(self, *args, **kwargs)
		self._precmd_handlers = []
		self._postcmd_handlers = []
		self._preloop_handlers = []
		self._postloop_handlers = []

	def do_detach(self, arg):
		self.trace_dispatch = None  # type: ignore
		self.set_continue()
		self._set_stopinfo(None, None, -1)  # type: ignore
		return True

	def precmd(self, line):
		print('precmdmesg')
		for handler in self._precmd_handlers:
			line = handler(line)

		line = pdb.Pdb.precmd(self, line)

		return line

	def  postcmd(self,stop,line):
		for handler in self._postcmd_handlers:
			line = handler(line)

		print('postcmdmesg')

		line = pdb.Pdb.postcmd(self,stop, line)

		return line

	def preloop(self):
		print('preloopmsg')
		pdb.Pdb.preloop(self)
		pass

	def postloop(self):
		print('postloomsg')
		pdb.Pdb.postloop(self)
		pass


	def attach_postloop_handler(self, handler):
		self._postloop_handlers.append(handler)


	def attach_preloop_handler(self, handler):
		self._preloop_handlers.append(handler)

	def attach_precmd_handler(self, handler):
		self._precmd_handlers.append(handler)

	def attach_postcmd_handler(self, handler):
		self._precmd_handlers.append(handler)


debugger = PdbDetach(stdin=sys.stdin, stdout=sys.stdout)
debugger.set_trace()

sys.stdin.write('n\n')

time.sleep(2)

n=10
factorial = 1


if int(n) >= 1:
	for i in range (1,int(n)+1):
		factorial = factorial * i

print("Factorail of ",n , " is : ",factorial)