//
//  NSObject+BlocksKit.m
//  BlocksKit
//

#import "NSObject+BlocksKit.h"

@implementation NSObject (BlocksKit)

+ (instancetype)bk_make:(void(^)(id obj))block {
	id obj = self.new;
	block(obj);
	return obj;
}

- (instancetype)bk_amend:(void (^)(id))block {
	block(self);
	return self;
}

@end
