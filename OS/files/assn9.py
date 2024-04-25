from prettytable import PrettyTable

def paginate(items, n):
    """Generate pages from items list with a specific number of items per page."""
    for i in range(0, len(items), n):
        yield items[i:i + n]

def main():
    memory = int(input("Enter the logical memory size in bytes: "))
    page = int(input("Enter the page size in bytes: "))
    physical_memory = int(input("Enter the physical memory size in bytes: "))

    total_items = memory // page
    physical_pages = min(physical_memory // page, total_items)  

    items = list(range(1, total_items + 1))
    pages = list(paginate(items, 1))

    table = PrettyTable()
    table.field_names = ["Page Number", "Page Content"]

    for i in range(physical_pages):
        table.add_row([i + 1, pages[i]])

    print(table)

if __name__ == "__main__":
    main()
    
    
    
    # The script now takes three inputs: logical memory size, page size, and physical memory siz
    # The number of total logical pages is computed by dividing the logical memory size by the page siz
    # The number of physical pages that can be displayed is the minimum of the number of pages that the physical memory can hold and the total logical page
    # A PrettyTable is used to output all the pages that fit within the physical memory in a single, well-formatted table at the end of the program, providing a clear overview of how the memory is divided and use
