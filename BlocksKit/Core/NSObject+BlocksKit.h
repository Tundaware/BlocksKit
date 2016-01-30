//
//  NSObject+BlocksKit.h
//  BlocksKit
//

#import <Foundation/Foundation.h>

@interface NSObject (BlocksKit)

/** Creates a new object, passes it to the provided block, and returns the new object.
 
 Allows you to create objects and set them up inline.
 
 [peopleArray addObject:[Person bk_make:^(Person *p) {
		p.name = @"George";
		p.age = 36;
 }]];
 
 @param block A single-argument, void-returning code block.
 @return an instance of the class
 */
+ (instancetype)bk_make:(void(^)(id obj))block;

/** Passes self to the provided block, and returns self
 
 Allows you to change an object inline and chaining. Similar to -[NSArray bk_each:] but for a
 single object.
 
 Person *p = ...;
 if (condition) {
	[self doSomethingWithPerson:[p bk_amend:^(Person *p) {
		// Change properties of p
	}]];
 } else {
	[self doSomethingWithPerson:[p bk_amend:^(Person *p) {
		// Change properties of p
	}]];
 }
 
 @param block A single-argument, void-returning code block.
 @return an instance of the class
 */
- (instancetype)bk_amend:(void(^)(id obj))block;

@end
