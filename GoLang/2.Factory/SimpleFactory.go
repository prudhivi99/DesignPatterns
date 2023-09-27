package main

import "fmt"

type logger interface {
	log()
}

type Debug struct {
}

type Error struct {
}

type Info struct {
}

func (d *Debug) log() {
	fmt.Println("Debug: msg")
}

func (e *Error) log() {
	fmt.Println("Error: msg")
}

func (i *Info) log() {
	fmt.Println("Info: msg")
}

func CreateLoggerFactory(s string) logger {
    if s == "Error" {
		return &Error{}
	} else if s == "Debug" {
		return &Debug{}
	} else if s== "Info" {
		return &Info{}
	} else {
		return nil
	}
}

func main() {
	loggerObj := CreateLoggerFactory("Error")
	loggerObj.log()
	loggerObj = CreateLoggerFactory("Debug")
	loggerObj.log()
}

