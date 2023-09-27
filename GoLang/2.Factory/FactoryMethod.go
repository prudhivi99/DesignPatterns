package main

import "fmt"

// Logger interface
type Logger interface {
	Log(msg string)
}

// Debug logger
type Debug struct{}

func (d *Debug) Log(msg string) {
	fmt.Printf("Debug: %s\n", msg)
}

// Error logger
type Error struct{}

func (e *Error) Log(msg string) {
	fmt.Printf("Error: %s\n", msg)
}

// Info logger
type Info struct{}

func (i *Info) Log(msg string) {
	fmt.Printf("Info: %s\n", msg)
}

// LoggerFactory interface
type LoggerFactory interface {
	CreateLogger() Logger
}

// DebugLoggerFactory creates Debug logger instances
type DebugLoggerFactory struct{}

func (D DebugLoggerFactory) CreateLogger() Logger {
	return &Debug{}
}

// ErrorLoggerFactory creates Error logger instances
type ErrorLoggerFactory struct{}

func (E ErrorLoggerFactory) CreateLogger() Logger {
	return &Error{}
}

// InfoLoggerFactory creates Info logger instances
type InfoLoggerFactory struct{}

func (I InfoLoggerFactory) CreateLogger() Logger {
	return &Info{}
}

func main() {
	// Create a DebugLoggerFactory
	debugFactory := DebugLoggerFactory{}

	// Use the factory to create a logger
	loggerObj1 := debugFactory.CreateLogger()

	// Log a message using the created logger
	loggerObj1.Log("This is a debug message")
}
