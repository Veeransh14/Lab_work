class File:
    def __init__(self, name):
        self.name = name
        self.content = ""

    def write(self, data):
        """Write data to the file."""
        self.content += data

    def read(self):
        """Read data from the file."""
        return self.content

class Directory:
    def __init__(self, name):
        self.name = name
        self.files = {}
        self.directories = {}

    def create_file(self, file_name):
        """Create a new file in the directory."""
        if file_name in self.files:
            raise Exception(f"File '{file_name}' already exists.")
        self.files[file_name] = File(file_name)

    def write_to_file(self, file_name, data):
        """Write data to a file in the directory."""
        if file_name not in self.files:
            raise Exception(f"File '{file_name}' does not exist.")
        self.files[file_name].write(data)

    def read_from_file(self, file_name):
        """Read data from a file in the directory."""
        if file_name not in self.files:
            raise Exception(f"File '{file_name}' does not exist.")
        return self.files[file_name].read()

    def list_contents(self):
        """List all files and directories within this directory."""
        return list(self.files.keys()) + list(self.directories.keys())

    def add_directory(self, dir_name):
        """Add a new directory within this directory."""
        if dir_name in self.directories:
            raise Exception(f"Directory '{dir_name}' already exists.")
        self.directories[dir_name] = Directory(dir_name)

    def get_directory(self, dir_name):
        """Get a directory by name."""
        if dir_name not in self.directories:
            raise Exception(f"Directory '{dir_name}' does not exist.")
        return self.directories[dir_name]

def main():
    root = Directory("root")
    root.create_file("test.txt")
    root.write_to_file("test.txt", "Hello, this is a test file.")

    print("File 'test.txt' content:", root.read_from_file("test.txt"))
    print("Contents of root directory:", root.list_contents())

    root.add_directory("subdir")
    subdir = root.get_directory("subdir")
    subdir.create_file("notes.txt")
    subdir.write_to_file("notes.txt", "Notes in a subdirectory file.")

    print("File 'notes.txt' in subdir:", subdir.read_from_file("notes.txt"))
    print("Contents of subdir:", subdir.list_contents())

if __name__ == "__main__":
    main()
