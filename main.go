package main

import (
	"log"
	"os"
)

func main() {
	ReadMulti()
}

func ReadSingle() {
	file, err := os.Create("/Users/y-okubo/mnt/Users/y-okubo/test.txt")
	if err != nil {
		log.Println(err)
		os.Exit(1)
	}
	defer file.Close()

	b := make([]byte, 4)
	for {
		n, err := file.Read(b)
		if n == 0 {
			log.Println("Read 0")
			break
		}
		if err != nil {
			log.Println(err)
			break
		}

		log.Print(string(b[:n]))
	}
}

func ReadMulti() {
	var files [10]*os.File
	var err error

	for _, file := range files {
		file, err = os.Create("/Users/y-okubo/mnt/Users/y-okubo/test.txt")
		if err != nil {
			log.Println(err)
			os.Exit(1)
		}
		defer file.Close()

		b := make([]byte, 4)
		for {
			n, err := file.Read(b)
			if n == 0 {
				log.Println("Read 0")
				break
			}
			if err != nil {
				log.Println(err)
				break
			}

			log.Print(string(b[:n]))
		}
	}
}
