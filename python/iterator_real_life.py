import time

class ReadWord:
	def __init__(self, file):
		self.file = file
	def __iter__(self):
		with open(self.file) as fh:
			while True:
				line = fh.readline();
				if line.strip() == "EOF":
					print("breaking")
					break
				elif not line:
					time.sleep(0.1)
					continue;
				else:
					for word in line.split():
						yield word



if __name__ == '__main__':
	r = ReadWord('names.txt')
	for word in r:
		print(word)
