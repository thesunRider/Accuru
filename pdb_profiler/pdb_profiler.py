import pdb
import sys

class PdbDetach(pdb.Pdb):
	use_rawinput = False

	def __init__(self, *args, **kwargs):
		pdb.Pdb.__init__(self, *args, **kwargs)
		self._precmd_handlers = []
		self._postcmd_handlers = []

	def do_detach(self, arg):
		self.trace_dispatch = None  # type: ignore
		self.set_continue()
		self._set_stopinfo(None, None, -1)  # type: ignore
		return True

	def precmd(self, line):
		for handler in self._precmd_handlers:
			line = handler(line)

		line = pdb.Pdb.precmd(self, line)

		return line

	def  postcmd(self,line):
		for handler in self._postcmd_handlers:
			line = handler(line)

		line = pdb.Pdb.postcmd(self, line)

		return line


	def attach_precmd_handler(self, handler):
		self._precmd_handlers.append(handler)

	def attach_postcmd_handler(self, handler):
		self._precmd_handlers.append(handler)


debugger = PdbDetach(stdin=sys.stdin, stdout=sys.stdout)
