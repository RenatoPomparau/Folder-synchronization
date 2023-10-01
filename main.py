import os
import shutil
import hashlib
import sys
import time

def md5(file_path):
    md5 = hashlib.md5()
    with open(file_path, 'rb') as file:
        while True:
            batch=file.read(4096)
            if batch:
                md5.update(batch)
            else:
                break
    return md5.hexdigest()


def sync(source_folder, destination_folder):
    f = open("output.txt", 'a')
    for root, dirs, files in os.walk(source_folder):
        # print("Root:", root)
        #print("dir",dirs)
        # print("files",files)
        # print()
        for file in files:
            source_path = os.path.join(root, file)
            # print(source_path)
            # print()
            # print( os.path.relpath(source_path, source_folder))
            # print()
            destination_path = os.path.join(destination_folder, os.path.relpath(source_path, source_folder))
            if os.path.exists(destination_path):
                if md5(source_path) != md5(destination_path):
                    print(f"Synchronizing {source_path} to {destination_path}")
                    f.write(f"Synchronizing {source_path} to {destination_path}\n")
                    shutil.copy2(source_path, destination_path)
            else:
                print(f"Copying {source_path} to {destination_path}")
                f.write(f"Copying {source_path} to {destination_path}\n")
                destination_dir = os.path.dirname(destination_path)
                os.makedirs(destination_dir, exist_ok=True)
                shutil.copy2(source_path, destination_path)

    for root, dirs, files in os.walk(destination_folder,topdown=False):
        # print("Root:", root)
        # print("dir", dirs)
        # print("files", files)
        # print()
        for file in files:
            destination_path=os.path.join(root,file)
            source_path=os.path.join(source_folder,os.path.relpath(destination_path,destination_folder))

            if os.path.exists(source_path)==False:
                print(f"Deleting {destination_path}")
                f.write(f"Deleting {destination_path}\n")
                os.remove(destination_path)
                print(os.path.dirname(destination_path))
                while True:
                    try:
                        destination_path=os.path.dirname(destination_path)
                        os.rmdir(destination_path)
                        print(f"Removing the folder from which we deleted the file if is empty  {destination_path}")
                        f.write(f"Removing the folder from which we deleted the file if is empty  {destination_path}\n")
                    except OSError as o:
                        print(f"Error, {o.strerror}: {destination_path}")
                        break
    f.close()

if __name__ == "__main__":

    # terminal python main.py "C:\Sincronizare\Source_folder" "C:\Sincronizare\Destination_folder" 5
    source_folder = "C:\Sincronizare\Source_folder"
    destination_folder = "C:\Sincronizare\Destination_folder"
    args_list=sys.argv
    #print(args_list)

    while True:
        sync(args_list[1],args_list[2])
        time.sleep(int(args_list[3]))
