# Page simulation in python 
class MemoryManagementUnit:
    def __init__(self, page_size, num_pages):
        self.page_size = page_size
        self.num_pages = num_pages
        self.page_table = {i: None for i in range(num_pages)}  

    def allocate_page(self, page_number, frame_number):
        """Allocate a page to a specific frame in memory."""
        if self.page_table[page_number] is None:
            self.page_table[page_number] = frame_number
            print(f"Page {page_number} allocated to frame {frame_number}.")
        else:
            print(f"Page {page_number} is already allocated to frame {self.page_table[page_number]}.")

    def translate_address(self, logical_address):
        """Translate a logical address to a physical address."""
        page_number = logical_address // self.page_size
        offset = logical_address % self.page_size
        
        if page_number in self.page_table and self.page_table[page_number] is not None:
            frame_number = self.page_table[page_number]
            physical_address = frame_number * self.page_size + offset
            print(f"Logical address {logical_address} -> Physical address {physical_address}")
            return physical_address
        else:
            print(f"Page fault at page number {page_number}!")
            return None


if __name__ == '__main__':
    mmu = MemoryManagementUnit(page_size=256, num_pages=16)
    
    
    mmu.allocate_page(0, 5)
    mmu.allocate_page(1, 8)
    
    
    mmu.translate_address(100)  
    mmu.translate_address(300)  
    mmu.translate_address(1024) 



    # MemoryManagementUnit Class: This class represents a simple MMU (Memory Management Unit).
    # Page Table: A dictionary is used to simulate a page table, where keys are page numbers and values are frame numbers (None if not yet mapped).
    # allocate_page Method: This method simulates allocating a page to a specific frame in memory.
    # translate_address Method: This method converts a logical address to a physical address using the page table. It checks if the page exists and has been allocated. If not, a "page fault" is reported.