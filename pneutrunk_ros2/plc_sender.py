
import tkinter as tk
from tkinter import ttk
import socket
from PIL import Image, ImageTk

# Function to send data via UDP
def send_udp():
    udp_ip = ip_entry.get()  # Get IP from the field
    udp_port = int(port_entry.get())  # Get port
    message = message_entry.get()  # Get message

    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.sendto(message.encode(), (udp_ip, udp_port))
        status_label.config(text=f"✅ Sent to {udp_ip}:{udp_port}", fg="green")
        print(f"✅ Sent to {udp_ip}:{udp_port} -> {message}")  # Log to console
    except Exception as e:
        status_label.config(text=f"❌ Error: {e}", fg="red")
        print(f"❌ Error: {e}")  # Log to console

# Create the window
root = tk.Tk()
root.title("UDP Sender")
root.geometry("1000x300")
root.resizable(True, True)

image = Image.open("/Users/xggrinch/Downloads/logo1.jpeg")  # Specify path to file
image = image.resize((100, 100))  # Resize image
photo = ImageTk.PhotoImage(image)

# Position the image at coordinates (x=200, y=150)
label = tk.Label(root, image=photo)
label.place(x=800, y=50)  # Exact positioning

# Title label
title_label = tk.Label(root, text="UDP Sender", font=("Arial", 14, "bold"))
title_label.pack(pady=10)

# Main frame
frame = tk.Frame(root, padx=15, pady=10)
frame.pack(pady=10)

# IP address input field
tk.Label(frame, text="IP Address:").grid(row=0, column=0, sticky="w")
ip_entry = ttk.Entry(frame, width=30)
ip_entry.insert(0, "192.168.100.5")  # Default value
ip_entry.grid(row=0, column=1, padx=5, pady=5)

# Port input field
tk.Label(frame, text="Port:").grid(row=1, column=0, sticky="w")
port_entry = ttk.Entry(frame, width=10)
port_entry.insert(0, "12050")  # Default value
port_entry.grid(row=1, column=1, padx=5, pady=5)

# Message input field
tk.Label(frame, text="Message:").grid(row=2, column=0, sticky="w")
message_entry = ttk.Entry(frame, width=50)
message_entry.insert(0, "tlak1:245,235,345,554,567,556,tlak2:354,65,435,56,6,67,67,end")
message_entry.grid(row=2, column=1, padx=5, pady=5)

# Send button
send_button = ttk.Button(root, text="Send", command=send_udp)
send_button.pack(pady=10)

# Status label
status_label = tk.Label(root, text="", fg="blue")
status_label.pack()

# Run the GUI
root.mainloop()

print(send_udp.message)  # debug
