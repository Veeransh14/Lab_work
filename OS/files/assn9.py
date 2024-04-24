def paginate(items, n):
    """Generate pages from items list with a specific number of items per page."""
    for i in range(0, len(items), n):
        yield items[i:i + n]

def main():
    # User input for total number of items and items per page
    total_items = int(input("Enter the total number of items: "))
    n = int(input("Enter the number of items per page: "))

    # Create a list of items based on the total number specified
    items = list(range(1, total_items + 1))

    # Create the pages
    pages = list(paginate(items, n))
    
    cp = 0

    while True:
        # Display current page
        print(f"Page {cp + 1}/{len(pages)}: {pages[cp]}")
        
        # User input for navigation
        command= input("Enter 'n' to go to the next page, 'p' to go to the previous page, or 'q' to quit: ").strip().lower()

        if command== 'n':
            if cp < len(pages) - 1:
                cp += 1
            else:
                print("You are on the last page.")
        elif command== 'p':
            if cp > 0:
                cp -= 1
            else:
                print("You are on the first page.")
        elif command== 'q':
            print("Exiting the page.")
            break
        else:
            print("Invalid input. Please try again.")

if __name__ == "__main__":
    main()

